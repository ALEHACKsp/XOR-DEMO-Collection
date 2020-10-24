<?php
error_reporting(0);
function Decrypt($string,$XORKey){
    $data = array_map('ord', str_split(base64_decode($string)));
    $XORKey = array_map('ord', str_split($XORKey));
    $length = count($data);
    $keyLength = count($XORKey);
    
    $keyCount = 0;
    
    $string = "";

    for ($i = 0; $i < $length; $i++) { 
        $string .= chr($data[$i] ^ $XORKey[$keyCount]);
        $keyCount++;
        if($keyCount>=$keyLength){
            $keyCount = 0;
        }
    }
    return $string;
}
function Encrypt($string,$XORKey){
    $data = array_map('ord', str_split($string));
    $XORKey = array_map('ord', str_split($XORKey));
    $length = count($data);
    $keyLength = count($XORKey);
    
    $keyCount = 0;
    
    $string = "";

    for ($i=0; $i < $length; $i++) { 
        $string .= chr($data[$i] ^ $XORKey[$keyCount]);
        $keyCount++;
        if($keyCount>=$keyLength){
            $keyCount = 0;
        }
    }
    $string = base64_encode($string);
    return $string;
}

?>
