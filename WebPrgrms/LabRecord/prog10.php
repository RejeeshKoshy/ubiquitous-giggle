<?php
$fruits = ["Apple", "Banana", "Cherry", "Date"];
$search = "Banana";

if (in_array($search, $fruits)) {
    echo "$search is in the array.";
} else {
    echo "$search is not in the array.";
}

$inputString = "Hello, World!";
$trimmedString = trim($inputString);
$regexPattern = "/\w+/";
preg_match_all($regexPattern, $trimmedString, $matches);
echo "<pre>" . print_r($matches, true) . "</pre>";
?>
