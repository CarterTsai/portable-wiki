'use strict';

angular.module('styleApp')
  .controller('MainCtrl', function ($scope, DB) {
      $scope.isShowMenu = true;
      
      $('.ui.dropdown').dropdown();
      
      $scope.lists = {
          "0": {"index":"Getting Started","sub": ["WikiHome","WikiHelp"]},
          "1": {"index":"Introduction","sub": ["Who is Wiki"]}
      }

      $scope.contents = DB.get();

      $scope.title = "";
      $scope.createContent = "";
      $scope.liveContent = "";
      
      $scope.Preview = function() {
         $scope.liveContent = '<h1 class="ui header">' +
                                $scope.title + '</h1><p>'+
                                $scope.createContent+'</p>'; 
      }

      $scope.show = function(index) {
         $scope.contents[index] = $(".d"+index+" > textarea").val();
      }

      $scope.create = function () {
        $scope.contents = DB.create($scope.liveContent);
      }

      $scope.edit = function (index) {
      }
      
      $scope.delete = function (index) {
          $('.ui.modal')
              .modal('setting', {
                   closable  : false,
                   onDeny    : function(){
                   },
                   onApprove : function() {
                     $scope.$apply(function() {
                        $scope.contents.splice(index ,1);
                        if($scope.contents.length == 0)
                            $scope.contents = [""];
                     })
                   }
                 })
              .modal('show');
      }
  });
