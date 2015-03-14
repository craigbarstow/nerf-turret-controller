// modules =================================================
var express        	= require('express');
var app            	= express();

// configuration ===========================================
var port = process.env.PORT || 8000; // set our port

app.use(express.static(__dirname + '/public')); // set the static files location /public/img will be /img for users

// routes ==================================================
require('./app/routes')(app); // configure our routes

// start app ===============================================
app.listen(port);										// startup our app at http://localhost:8080
console.log("It's goin down on port " + port); 			// shoutout to the user
exports = module.exports = app; 						// expose app
