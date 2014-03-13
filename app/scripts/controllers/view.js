'use strict';

angular.module('styleApp')
  .controller('ViewCtrl', function ($scope, DB, $http ,$routeParams, $location) {
    $scope.isShowMenu = true;
    $scope.content = "";
    $scope.editContent = [];

    $scope.contentId = $routeParams.contentId;
       
    DB.htmlGet($scope.contentId, function(data, status) {
          if (status != 404) {
              $scope.content = data;
          } else {
               $location.path('/');
          }
    });

    $scope.show = function(index) {
       var _tmp = $(".d"+index+" > textarea").val();
       DB.updateWiki($scope.contentId, _tmp, function(data){
         
        var slice_length = 1024;
        var slice_num = _tmp.length / slice_length;      
        var slice_start = 0;
        var slice_end = slice_length;
        $scope.content = "";
        
        for(var i=0; i< slice_num  ;) {
            i++;
            var slice_data = _tmp.slice(slice_start, slice_end);
            slice_start = (i * slice_length) -1 ;
            slice_end = slice_length + slice_start; 

            DB.preview(slice_data, i ,function(html) { 
              $scope.content += html;
            });
        }
       }); 
    }

    $scope.edit = function (index) {
        DB.wikiGet($scope.contentId, function(data) {
          $scope.editContent[index]=data;
        });
    }
    
    $scope.delete = function (name) {
        $('.ui.modal')
            .modal('setting', {
                 closable  : false,
                 onDeny    : function(){
                 },
                 onApprove : function() {
                   $scope.$apply(function() {
                      DB.del(name, function(data, status) {
                           $location.path("/");                                        
                      });
                   })
                 }
               })
            .modal('show');
    }
  });
