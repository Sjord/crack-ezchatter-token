<?php
// Copyright (c) 2015 Vincent Chi
// MIT License
// https://github.com/ChiVincent/EZChatter

class Token {
    public static function gen($len = 5)
    {
        $token = '';
        while($len--){
            $choose = rand(0, 2);
            if ($choose === 0)
                $token .= chr(rand(ord('A'), ord('Z')));
            else if($choose === 1)
                $token .= chr(rand(ord('a'), ord('z')));
            else
                $token .= chr(rand(ord('0'), ord('9')));
        }
        return $token;
    }

}
