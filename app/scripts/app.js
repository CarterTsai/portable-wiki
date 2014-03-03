'use strict';

angular.module('styleApp', [
  'ngSanitize',
  'ngRoute'
])
  .config(function ($routeProvider, $locationProvider) {
    $routeProvider
      .when('/', {
        templateUrl: 'views/main.html',
        controller: 'MainCtrl'
      })
      .when('/Create', {
        templateUrl: 'views/create.html',
        controller: 'MainCtrl'
      })
      .when('/View/:contentId', {
        templateUrl: 'views/view.html',
        controller: 'ViewCtrl'
      })
      .when('/Index', {
        templateUrl: 'views/index.html',
        controller: 'MainCtrl'
      })
      .when('/Changes', {
        templateUrl: 'views/changes.html',
        controller: 'MainCtrl'
      })
      .when('/About', {
        templateUrl: 'views/about.html',
        controller: 'MainCtrl'
      })
      .when('/Help', {
        templateUrl: 'views/help.html',
        controller: 'MainCtrl'
      })
      .when('/Search', {
        templateUrl: 'views/search.html',
        controller: 'SearchCtrl'
      })
      .otherwise({
        redirectTo: '/'
      });

   // $locationProvider.html5Mode(true);
  });
