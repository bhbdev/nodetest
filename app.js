
/**
 * Module dependencies.
 */

var express = require('express')
  , routes = require('./routes');

var app = express();

// Configuration

app.set('views', __dirname + '/views');
app.set('view engine', 'pug');
app.use(express.json());
app.use(express.urlencoded({ extended: true }));
app.use(express.static(__dirname + '/public'));

if (app.get('env') === 'development') {
  app.use(require('errorhandler')({ dumpExceptions: true, showStack: true }));
}

if (app.get('env') === 'production') {
  app.use(require('errorhandler')());
}

// Routes

app.get('/', routes.index);
app.post('/say', routes.say);

app.listen(3000, function(){
  console.log("Express server listening on port %d in %s mode", this.address().port, app.settings.env);
});
