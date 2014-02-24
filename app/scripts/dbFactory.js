'use strict';
// return the function's  return value
angular.module('styleApp')
.factory('DB', function() {

    var base = {};
    var content = ['<h1 class="ui header">Welcome to PortableWiki</h1><p>PortableWiki is a small and simple WikiWikiWeb implementation Ideal for personal note-taking, "to do" lists, and any other uses you can think of. It is fast and does not require webserver, database mng and php interpreter.For an example of how a PortableWiki entry looks in text form you can edit this page. Also see WikiHelp for infomation on usage and formatting rules. Use The WikiSandbox to experiment.</p><br>', '<h1 class="ui header">Test 2</h1><p> I wish this good UI']
;
    var info = {};

    base.get = function() {
        return content;
    } 

    base.create = function(data, title) {
        content.push(data);
        return content;
    }
    
    var factoryFunction = {
        get   : base.get,
        edit   : base.put,
        del    : base.del,
        create : base.create
    };
    return factoryFunction;
});
