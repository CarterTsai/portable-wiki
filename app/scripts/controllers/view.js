'use strict';

angular.module('styleApp')
  .controller('ViewCtrl', function ($scope, DB, $http , $routeParams) {
      $scope.isShowMenu = true;
      $scope.content = "";
      $scope.editContent = [];
      $scope.lists = [];

      $scope.contentId = $routeParams.contentId;
      
      DB.getList(function(data){
         $scope.lists = data;
         DB.htmlGet(data[$scope.contentId], function(data) { 
            $scope.content = data;
        });
      }); 
       
      $scope.show = function(index) {
         var _tmp = $(".d"+index+" > textarea").val();
         DB.updateWiki($scope.lists[index], _tmp );
         
         DB.htmlGet($scope.lists[index], function(data) { 
           $scope.content = data;
         });
      }

      $scope.edit = function (index) {
          console.log($scope.lists[index]);
          DB.wikiGet($scope.lists[index], function(data) {
            $scope.editContent[index]=data;
          });
      }
      
      $scope.delete = function (index) {
          $('.ui.modal')
              .modal('setting', {
                   closable  : false,
                   onDeny    : function(){
                   },
                   onApprove : function() {
                     $scope.$apply(function() {
                        DB.del(index);
                        $scope.content = "";
                     })
                   }
                 })
              .modal('show');
      }
  });
