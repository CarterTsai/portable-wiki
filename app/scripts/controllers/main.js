'use strict';

angular.module('styleApp')
  .controller('MainCtrl', function ($scope, DB, $http, $location) {
      $scope.isShowMenu = true;
      $scope.contents = [];
      $scope.helpContent = "";
      $scope.editContent = [];
      $scope.lists = [];
      $scope.title = "";
      $scope.createContent = "";
      $scope.liveContent = "";
      
      $('.ui.dropdown').dropdown();
      
      DB.getList(function(data){
            $scope.lists.push(data); 
      });  
    
      DB.htmlGet("WikiHome", function(data) { 
            $scope.contents.push(data);
      });
       
      DB.htmlGet("WikiHelp", function(data) {
           $scope.helpContent = data;
      }); 
      
      $scope.Preview = function() {
        var _content  = "="+ $scope.title +"\n" + $scope.createContent;
         DB.preview(_content ,function (html) { 
             $scope.liveContent = html;
         });
      }

      $scope.show = function(index) {
         var _tmp = $(".d"+index+" > textarea").val();
         DB.updateWiki("WikiHome", _tmp, function(data){
            DB.htmlGet("WikiHome", function(html) { 
                $scope.contents[index] = html ;
            });
         });   
      }

      $scope.create = function () {
           var _content = "= " + $scope.title + "\n" + $scope.createContent;
           DB.create(_content, $scope.title, function(data) { 
                console.log("create success!!");
                DB.updateList(function(data){
                    console.log("updateList");
                    $scope.lists.push(data);
                    $location.path("/");
                });  
           });
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
