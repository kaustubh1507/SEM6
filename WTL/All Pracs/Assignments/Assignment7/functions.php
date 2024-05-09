<?php
include 'db_connection.php';

// Add a new book
function addBook($title, $author, $genre, $publication_year) {
    global $conn;
    $sql = "INSERT INTO books (title, author, genre, publication_year) 
            VALUES ('$title', '$author', '$genre', $publication_year)";
    return $conn->query($sql);
}

// Update an existing book
function updateBook($id, $title, $author, $genre, $publication_year) {
    global $conn;
    $sql = "UPDATE books 
            SET title='$title', author='$author', genre='$genre', publication_year=$publication_year 
            WHERE id=$id";
    return $conn->query($sql);
}

// Delete a book
function deleteBook($id) {
    global $conn;
    $sql = "DELETE FROM books WHERE id=$id";
    return $conn->query($sql);
}

// Retrieve all books
function getBooks() {
    global $conn;
    $sql = "SELECT * FROM books";
    $result = $conn->query($sql);
    $books = [];
    if ($result->num_rows > 0) {
        while ($row = $result->fetch_assoc()) {
            $books[] = $row;
        }
    }
    return $books;
}
?>
