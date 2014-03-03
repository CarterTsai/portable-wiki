'use strict';

angular.module('styleApp')
  .controller('SearchCtrl', function ($rootScope, $scope, DB) {
      $rootScope.searchContent = DB.searchContent; 
  });
