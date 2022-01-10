#!/usr/bin/node
const request = require('request');
const id = process.argv[2];
const url = `https://swapi-api.hbtn.io/api/films/${id}`;
request.get(url, async (error, res) => {
  if (error) console.log(error);
  else {
    const mainErray = JSON.parse(res.body);
    tryExecuteNext(mainErray.characters, 0);
  }
});

const tryExecuteNext = (mainErray, index) => {
  request.get(mainErray[index], (error, res, body) => {
    if (error) throw error;
    const result = JSON.parse(body);
    console.log(result.name);
    if (index < mainErray.length - 1) {
      tryExecuteNext(mainErray, index + 1);
    }
  });
};
