'use strict';

angular.module('styleApp')
  .controller('MainCtrl', function ($scope, DB, $http) {
      $scope.isShowMenu = true;
      $scope.contents = [];
      $scope.helpContent = "";
      $scope.editContent = [];

      $('.ui.dropdown').dropdown();
      
      $scope.lists = {
          "0": {"index":"Getting Started","sub": ["WikiHome","WikiHelp"]},
          "1": {"index":"Introduction","sub": ["Who is Wiki"]}
      };
      
      DB.htmlGet("WikiHome", function(data) { 
           $scope.contents.push(data);
      });
      
      DB.htmlGet("WikiHelp", function(data) {
           $scope.helpContent = data;
      });
 
      $scope.title = "";
      $scope.createContent = "";
      $scope.liveContent = "";
      
      $scope.Preview = function() {
         $scope.liveContent = '<h1 class="ui header">' +
                                $scope.title + '</h1><p>'+
                                $scope.createContent+'</p>'; 
      }

      $scope.show = function(index) {
         var _tmp = $(".d"+index+" > textarea").val();
         DB.updateWiki("WikiHome", _tmp);
         
         DB.htmlGet("WikiHome", function(data) { 
           $scope.contents[index] = data;
         });
      }

      $scope.create = function () {
        $scope.contents = DB.create($scope.liveContent);
      }

      $scope.edit = function (index) {
          DB.wikiGet("WikiHome", function(data) {
            $scope.editContent[0]=data;
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
                        $scope.contents.splice(index ,1);
                        if($scope.contents.length == 0)
                            $scope.contents = [""];
                     })
                   }
                 })
              .modal('show');
      }
  });
