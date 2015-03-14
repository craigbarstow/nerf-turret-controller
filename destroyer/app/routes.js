var request 	   	= require('request');


module.exports = function(app) {

	// server routes ===========================================================
	app.get('/', function(req, res) {
		res.sendfile('./public/views/index.html');
	});

};
