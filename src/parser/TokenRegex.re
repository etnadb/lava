module Rex = {

  module Types = {
    let string  = [%bs.re "/^&s(tring)?$/"];
    let integer = [%bs.re "/^&i(nt)?$/"];
    let float   = [%bs.re "/^&f(loat)?$/"];
    let boolean = [%bs.re "/^&b(ool)?$/"];
    let json    = [%bs.re "/^&j(son)?$/"];
  };

  module Values = {
    let string  = [%bs.re "/(\"|')(?:\\\1|[^\\1])*?\1/"];
    let integer = [%bs.re "/^\d+$/"];
    let float   = [%bs.re "/^[-+]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?$/"];
    let boolean = [%bs.re "/true|false/i"];
  };

  let key = [%bs.re "/^[:|_|#|$|%|\\w]*$/gi"];

};