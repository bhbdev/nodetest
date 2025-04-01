
/*
 * GET home page.
 */

exports.index = function(req, res){
	
	var h = require('../ext/lib/hello');
	var hs = require('../ext/lib/hellosimple');
	
  res.render('index', { 
		title: 'Node Test' ,
		hello: (new h.HelloWorld).hello(),
		hellosimple: hs.hello()
  })
};