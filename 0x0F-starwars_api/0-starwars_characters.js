#!/usr/bin/node
const request = require('request');
const movieId = process.argv[2];
const url = `https://swapi-api.hbtn.io/api/films/${movieId}`;
request(url, async (error, response, body) => {
  if (!error) {
    const characters = JSON.parse(body).characters;
    for (const charId in characters) {
      await new Promise((resolve, reject) => {
        request(characters[charId], (error, response, body) => {
          if (!error) {
            console.log(JSON.parse(body).name);
            resolve();
          }
        });
      });
    }
  }
});
