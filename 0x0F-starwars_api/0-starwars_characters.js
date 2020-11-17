#!/usr/bin/node
const request = require('request');

/* consumes films by argument*/
const url = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2];
request(url, { json: true }, (err, res, body) => {
	let index = 0
	if (err) { return console.log(err); }
	fnCharacters(body.characters, 0);
});
/* function to get characters by film */
/* invokes recursively(SYNC) to execute in order NOASYNC*/
const fnCharacters = function GetCharacters(arrayurl, index) {
	if (arrayurl.length === index) return;
	request(arrayurl[index], { json: true }, (err, res, body) => {
		if (err) { return console.log(err); }
		console.log(body.name);
		fnCharacters(arrayurl, index + 1);
	});
}
