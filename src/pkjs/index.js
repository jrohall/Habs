// import clay package
var Clay = require('@rebble/clay');
// load clay config file
var clayConfig = require('./config');
// initialize clay
var clay = new Clay(clayConfig);

Pebble.addEventListener('ready',
	function(e) {
			console.log('PebbleKit JS ready!');
	}
);
