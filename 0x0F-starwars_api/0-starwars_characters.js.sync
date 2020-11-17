#!/usr/bin/node
const request = require('request');

const url = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2];
request(url, { json: true }, (err, res, body) => {
  if (err) { return console.log(err); }
  for (const i in body.characters) {
    request(body.characters[i], { json: true }, (err, res, body) => {
      if (err) { return console.log(err); }
      console.log(body.name);
    });/* request */
  } /* for */
});
