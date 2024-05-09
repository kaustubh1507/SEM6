<?php
include 'functions.php';

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $title = $_POST["title"];
    $author = $_POST["author"];
    $genre = $_POST["genre"];
    $publication_year = $_POST["publication_year"];
    
    if (addBook($title, $author, $genre, $publication_year)) {
        echo "Book added successfully.";
    } else {
        echo "Error adding book.";
    }
}
?>
