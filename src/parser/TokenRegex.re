module Rex = {

  module Types = {
    let string  = [%bs.re "/^&s(tring)?$/"];
    let integer = [%bs.re "/^&i(nt)?$/"];
    let float   = [%bs.re "/^&f(loat)?$/"];
    let boolean = [%bs.re "/^&b(ool)?$/"];
    let json    = [%bs.re "/^&j(son)?$/"];
  };

  let key = [%bs.re "/^[:|_|#|$|%|\\w]*$/gi"];
};