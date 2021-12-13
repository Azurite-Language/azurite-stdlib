let rec add_list = function [] -> 0. | e::l -> e +. (add_list l)

let sbt_list x =
    let rec sbt_one = function e::l -> e *. (-1.) in
    let rec sbt_multi = function [] -> 0. | e::l -> e -. (add_list l) in
    let sbt_switcher x = if List.length x = 1 then sbt_one x else sbt_multi x in
    sbt_switcher x

let rec mtp_list = function [] -> 1. | e::l -> e *. (mtp_list l)

let div_list x = 
    let rec div_one = function e::l -> 1.0 /. e in
    let rec div_multi = function [] -> 1. | e::l -> e /. (mtp_list l) in
    let rec div_switcher x = if List.length x = 1 then div_one x else div_multi x in
    div_switcher x

let round = Float.round

let sin = sin
let cos = cos
let tan = tan
let sqrt = sqrt
let exp = exp;;
let ln = log;;

let float_of_bool = function false -> 1. | true -> 0.
let bool_of_float = function 0. -> false | _ -> true

let azur_bool_of_string = function "" | "false" | "0" | "0." | "0.0" -> false | _ -> true

let rec follows_comp op = function [] -> true | _::[] -> true | e1::e2::l -> (op e1 e2) && (follows_comp op (e2::l))

let is_num s = try float_of_string s |> ignore; true with Failure _ -> false

let rec cat = function [] -> "" | e::l -> e ^ (cat l) 

let begins_with_s str to_search = if to_search = "" then true else if str = "" then false else
    let length = String.length to_search - 1 in if length > String.length str - 1 then false else
    let rec check_in_pos pos = function 0 -> true | x -> (String.get str (pos + x) ) = (String.get to_search (x)) && (check_in_pos pos (x - 1)) in
    check_in_pos 0 length;;

let ends_with_s str to_search = if to_search = "" then true else if str = "" then false else
    let length = String.length to_search - 1 in if length > String.length str - 1 then false else
    let rec check_in_pos pos = function 0 -> true | x -> (String.get str (pos + x) ) = (String.get to_search (x)) && (check_in_pos pos (x - 1)) in
    check_in_pos (String.length str - length - 1) length;;

let rec azur_or = function [] -> false | e::l -> e || azur_or l
let rec azur_and = function [] -> true | e::l -> not e || azur_and l
let rec azur_xor = function l -> (azur_or l) && not (azur_and l)

let rec azur_lst_equal = function ([], []) -> true | ([e], []) | ([], [e]) -> false | (e1::l1, e2::l2 ) -> (e1 = e2) && azur_lst_equal (l1, l2)  

let begins_with_l str to_search = if to_search = [] then true else if str = [] then false else
    let length = List.length to_search - 1 in if length > List.length str - 1 then false else
    let rec check_in_pos pos = function 0 -> true | x -> (List.nth str (pos + x) ) = (List.nth to_search (x)) && (check_in_pos pos (x - 1)) in
    check_in_pos 0 length;;

let ends_with_l str to_search = if to_search = [] then true else if str = [] then false else
    let length = List.length to_search - 1 in if length > List.length str - 1 then false else
    let rec check_in_pos pos = function 0 -> true | x -> (List.nth str (pos + x) ) = (List.nth to_search (x)) && (check_in_pos pos (x - 1)) in
    check_in_pos (List.length str - length - 1) length;;

