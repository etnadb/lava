open Jest;
open TokenRegex;

let validate = (re, str) => Js.Re.test_(re, str);

describe("Testing Types Regex", () => {
  open Expect;

  test("string type", () =>
    expect(validate(Rex.Types.string, "&string")) |> toBe(true))

  test("string type (shorthand)", () =>
    expect(validate(Rex.Types.string, "&s")) |> toBe(true))

  test("integer type", () =>
    expect(validate(Rex.Types.integer, "&int")) |> toBe(true))
  
  test("integer type (shorthand)", () =>
    expect(validate(Rex.Types.integer, "&i")) |> toBe(true))

  test("float type", () =>
    expect(validate(Rex.Types.float, "&float")) |> toBe(true))

  test("float type (shorthand)", () =>
    expect(validate(Rex.Types.float, "&f")) |> toBe(true))
  
  test("boolean type", () =>
    expect(validate(Rex.Types.boolean, "&bool")) |> toBe(true))

  test("boolean type (shorthand)", () =>
    expect(validate(Rex.Types.boolean, "&b")) |> toBe(true))

});