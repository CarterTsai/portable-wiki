'use strict';
// return the function's  return value
angular.module('styleApp')
.factory('DB', function($http) {

    var base = {};
    var content = "";
    var info = {};
    var _index = [];

    base.htmlGet = function(wikiname, cb) {
        $http({method: "GET", url: "html/"+wikiname})
              .success(function(data){ cb(data);});     
    } 
    
    base.wikiGet = function(wikiname, cb) {
        $http({method: "GET", url: "wiki/"+wikiname})
              .success(function(data){ cb(data);});     
    } 

    base.update = function(wikiname, _data, cb) {    
        $http({ method: "GET", 
                url: "wiki/"+wikiname,
                params: {update: 'y', data: _data}
              })
             .success(function(data){ cb(data);});     
    }
 
    base.updateList = function(cb) {
        $http({ method: "GET", 
                url: "list/"
              }).success(function(data){ _index = data; cb(data);});     
    }
    
    base.list = function(cb) {
        if( _index.length == 0 ) {
            $http({ method: "GET", 
                url: "list/"
              }).success(function(data){ _index = data; cb(data);});     
        } else {
            cb(_index);
        }
    }

    base.create = function(_data, title, cb) {
        $http({ method: "GET", 
                url: "wiki/"+title,
                params: {create: 'y', data: _data}
              })
              .success(function(data){ cb(data);});     
    }

    base.del = function(id) {
        console.log(_index[id]);
    }

    base.preview = function(content, cb) {
    
        $http({ method: "GET", 
                url: "html/",
                params: {preview: content}
              })
              .success(function(html){ cb(html);});     
    }

    base.change = function (cb){
        $http({ method: "GET", 
                url: "diff"
              })
              .success(function(html){cb(html);});      
    }
    
    var factoryFunction = {
        wikiGet   : base.wikiGet,
        htmlGet   : base.htmlGet,
        updateWiki : base.update,
        getList: base.list,
        updateList: base.updateList,
        edit   : base.put,
        del    : base.del,
        create : base.create,
        preview: base.preview,
        change : base.change
    };
    return factoryFunction;
});
