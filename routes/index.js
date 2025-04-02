
/*
 * GET home page.
 */

exports.index = function(req, res){
	
	var h = require('../ext/lib/hello');
	var hs = require('../ext/lib/hellosimple');
    var s = require('../ext/lib/say');
	
  res.render('index', { 
		title: 'Node Test' ,
		hello: (new h.HelloWorld).hello(),
		hellosimple: hs.hello(),
        say: s.say('Hello World from C++'),
  })
};


/*
 * POST say
 */
exports.say = function(req, res){
    var s = require('../ext/lib/say');
    
    var str = req.body.str;
    
    if (str) {
        res.render('say', {
            title: 'Say',
            say: s.say(str)
        });
    } else {
        res.send('No string provided');
    }
}