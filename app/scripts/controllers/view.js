'use strict';

angular.module('styleApp')
  .controller('ViewCtrl', function ($scope, DB, $http ,$routeParams, $location) {
      $scope.isShowMenu = true;
      $scope.content = "";
      $scope.editContent = [];
      $scope.lists = [];

      $scope.contentId = $routeParams.contentId;
      
      DB.getList(function(data){
         $scope.lists = data;
         DB.htmlGet($scope.contentId, function(data, status) { 
            if (status != 404) {
                $scope.content = data;
            } else {
                 $location.path('/');
            }
        });
      }); 
       
      $scope.show = function(index) {
         var _tmp = $(".d"+index+" > textarea").val();
         DB.updateWiki($scope.contentId, _tmp, function(data){
            DB.preview(_tmp, function(html) { 
                $scope.content = html;
            });
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
                          DB.updateList(function(data) {
                             $scope.lists = [];                                      
                             $scope.lists.push(data);                                
                             $location.path("/");                                        
                          });
                        });
                     })
                   }
                 })
              .modal('show');
      }
  });
