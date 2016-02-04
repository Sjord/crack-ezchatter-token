<?php
require_once('./token.php');

for ($i = 0; $i < PHP_INT_MAX; $i++) {
    srand($i);
    if (Token::gen(10) == "2118Jx9w3e") {
        die("Found: $i \n");
    }
}
