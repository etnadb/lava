open TokenRegex;

module Tokenizer = {

  type query =
  | Get(queryMap)
  | Set(queryMap)
  | Exist(queryMap)
  | Delete(queryMap)
  | Unknown

  and queryMap = {
    command: string,
    type':   string,
    key:     string,
    value:   string
  };

  let tokenize = (input) =>
    Js.String.split(" ", input);

  let getTokens = (tokens): query =>
    switch tokens {
      | [|"GET", key|]                 => Get    ({ command: "GET",    key: key, type': "",    value: "" })
      | [|"SET", type', key, value|]   => Set    ({ command: "SET",    key: key, type': type', value: value })
      | [|"EXIST", key|]               => Exist  ({ command: "EXIST",  key: key, type': "",    value: "" })
      | [|"DELETE", key|]              => Delete ({ command: "DELETE", key: key, type': "",    value: "" })
      | _ => Unknown
    };

  let validateQuery = (tokens: query) =>
    switch tokens {
      | Get(query)   => Validation.Tokens.keyFromQuery(query)
      | Set(query)   => "validateSet"
      | Exist(query) => "validateExist"
      | Delete(query) => "validateDelete"
      | _             => ""
    };

};
