#!/usr/bin/node

const request = require('request');
const url = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2];

request(url, async (error, response, body) => {
  if (error) {
    console.log(error);
  }
  response = JSON.parse(body);
  for (const charId of response.characters) {
    await new Promise((resolve, reject) => {
      request(charId, (error, response, body) => {
        if (error) {
          console.log(error);
        }
        const formatedResponse = JSON.parse(body);
        console.log(formatedResponse.name);
        resolve();
      });
    });
  }
});
