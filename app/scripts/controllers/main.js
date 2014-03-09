'use strict';

angular.module('styleApp')
  .controller('MainCtrl', function ($timeout, $rootScope,$scope, DB, $http, $location) {
      $scope.isShowMenu = true;
      $scope.contents = [];
      $scope.helpContent = "";
      $scope.editContent = [];
      $rootScope.lists = [];
      $scope.title = "";
      $scope.createContent = "";
      $scope.liveContent = "";
      $rootScope.diff = [];

      $('.ui.dropdown').dropdown();
       
      DB.htmlGet("WikiHome", function(data) { 
            $scope.contents.push(data);
      });
       
      DB.htmlGet("WikiHelp", function(data) {
           $scope.helpContent = data;
      }); 
      
      DB.change( function(data) {
           $rootScope.diff = [];
           $rootScope.diff.push(data);
      });    
      
      $scope.updateIndex = function() {
        DB.updateList(function(data){
            $rootScope.lists = [];
            $rootScope.lists.push(data); 
        });  
      };

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
                $location.path("/");
           });
      }

      $scope.edit = function (index) {
          DB.wikiGet("WikiHome", function(data) {
            $scope.editContent[0]=data;
          });
      }

      $scope.changes = function () {
          console.log("changes");
          DB.change( function(data) {
              $rootScope.diff = [];
              $rootScope.diff.push(data);
          });    
      }

      $scope.search = function (event) {
          if(typeof event === 'undefined' || event.charCode == 13) {
              var expression = $(".search_offset > input").val();
              DB.search(expression, function(content, status) {
                 if(content.status == "ok") {
                    $rootScope.searchContent = content.data;
                    DB.searchContent = content.data;
                 } 
                $location.path("Search");
             })
         }
      }   

      $scope.delete = function (name) {
          $('.ui.modal')
              .modal('setting', {
                   closable  : false,
                   onDeny    : function(){
                   },
                   onApprove : function() {
                       $scope.$apply(function() {
                            DB.del(name, function() {
                                $location.path("/");
                            });
                       });
                   }
                 })
              .modal('show');
      }
      
      $rootScope.$on('ngRepeatFinished', function (ngRepeatFinishedEvent) {
          console.log("Repeat Finish");
          $timeout(function() {
               $rootScope.repeatHide = true;
          }, 500);
      });
  });

angular.module('styleApp')
  .controller('DiffCtrl', function ($rootScope,$scope, DB, $routeParams ,$location) {
        var diffCtrl = $location.path().slice(1,5);
        var diffName = $routeParams.name;
        $scope.diffContent = "No Changes Info";
        
        if (diffCtrl == 'Diff') {
            DB.diff(diffName, 'diff1' ,function(data, status) {
                if( status === 200 ) {
                    $scope.diffContent = data;
                }
                $rootScope.repeatHide = true; 
            });
        } else {
            DB.diff(diffName, 'diff2' ,function(data, status) {
                if( status === 200 ) {
                    $scope.diffContent = data;
                }
                $rootScope.repeatHide = true; 
            });
        }
  });
