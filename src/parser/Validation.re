open TokenRegex;

exception InvalidKeyFormat(string);

module Tokens = {

  let key = (key, query) =>
    switch (Js.Re.test_(Rex.key, key)) {
      | true => query
      | _    => raise(InvalidKeyFormat("Invalid key format: " ++ key))
    };

  let keyFromQuery = (query: Tokenizer.queryMap) =>
    key(query.key, query);
};