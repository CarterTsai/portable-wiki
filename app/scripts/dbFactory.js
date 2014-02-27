'use strict';
// return the function's  return value
angular.module('styleApp')
.factory('DB', function($http) {

    var base = {};
 //   var content = ['<h1 class="ui header">Welcome to PortableWiki</h1><p>PortableWiki is a small and simple WikiWikiWeb implementation Ideal for personal note-taking, "to do" lists, and any other uses you can think of. It is fast and does not require webserver, database mng and php interpreter.For an example of how a PortableWiki entry looks in text form you can edit this page. Also see WikiHelp for infomation on usage and formatting rules. Use The WikiSandbox to experiment.</p><br>', '<h1 class="ui header">Test 2</h1><p> I wish this good UI']
;
    var content = "";

    var info = {};

    base.htmlGet = function(wikiname, cb) {
        $http({method: "GET", url: "html/"+wikiname})
              .success(function(data){ cb(data);});     
    } 
    
    base.wikiGet = function(wikiname, cb) {
        $http({method: "GET", url: "wiki/"+wikiname})
              .success(function(data){ cb(data);});     
    } 

    base.update = function(wikiname, _data) {    
        $http({ method: "GET", 
                url: "wiki/"+wikiname,
                params: {update: 'y', data: _data}
              })
              .success(function(data){ cb(data);});     
    }

    base.list = function() {
    
    }

    base.create = function(_data, title, cb) {
        $http({ method: "GET", 
                url: "wiki/"+title,
                params: {create: 'y', data: _data}
              })
              .success(function(data){ cb(data);});     
    }
    
    var factoryFunction = {
        wikiGet   : base.wikiGet,
        htmlGet   : base.htmlGet,
        updateWiki : base.update,
        edit   : base.put,
        del    : base.del,
        create : base.create
    };
    return factoryFunction;
});
