open TokenRegex;

exception InvalidKeyFormat(string);
exception InvalidType(string);

module Tokens = {

  let key = (key, query) =>
    switch (Js.Re.test_(Rex.key, key)) {
      | true => query
      | _    => raise(InvalidKeyFormat("Invalid key format: " ++ key))
    };

  let value = (value, valType, query) => {
    open Tokenizer;

    switch valType {
      | String  => (Js.Re.test_(Rex.Values.string,  value)) ? query : raise(InvalidType("Invalid type: " ++ value))
      | Integer => (Js.Re.test_(Rex.Values.integer, value)) ? query : raise(InvalidType("Invalid type: " ++ value))
      | Float   => (Js.Re.test_(Rex.Values.float,   value)) ? query : raise(InvalidType("Invalid type: " ++ value))
      | Boolean => (Js.Re.test_(Rex.Values.boolean, value)) ? query : raise(InvalidType("Invalid type: " ++ value))
      | Json    => query
      | _       => raise(InvalidType("Invalid type: " ++ value))
    };

  };

  let keyFromQuery = (query: Tokenizer.queryMap) =>
    key(query.key, query);
};