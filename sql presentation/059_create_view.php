<!DOCTYPE html>
<html lang="en">

<head>
    <link rel="stylesheet" href="cs.css" />
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Create View Example</title>
    <style>
        .to {
            text-align: center;
            /* Centers text inside the box */
            color: rgb(0, 0, 0);
            font-size: 50px;
            font-family: "Georgia", serif;
            max-width: 290px;
            /* Limits the width of the box */
            padding: 14px;
            /* Adds space inside the box */
            background: bisque;
            /* White background */
            border-radius: 10px;
            /* Rounds the corners */
            box-shadow: 0 4px 15px rgba(0, 0, 0, 0.2);
            /* Adds shadow for depth */
            border: 2px solid rgb(7, 1, 0);
            /* Red border */
            margin: 0 auto 50px auto;
        }
    </style>
</head>

<body>
    <div>
        <p class="to">Create view</p>
    </div>
    <!-- Left-aligned content: Definition -->
    <div class="left-container">
        <p><b>Definition</b></p>
    </div>
    <p class="defination">
        A view in SQL is a virtual table created based on the result of a SELECT
        query. It does not store data itself but provides a way to simplify
        complex queries or improve security by restricting access to certain
        columns or rows
    </p>
    <!-- Left-aligned content: Code -->
    <div class="left-container">
        <p><b>Code</b></p>
    </div>
    <div>
        <pre class="code-box">
CREATE VIEW
        user_orders_view AS
    SELECT
        u.name,
        u.email,
        o.product,
        o.amount
    FROM
        users u
        INNER JOIN orders o ON u.id = o.user_id;</pre>
    </div>

    <?php
    $servername = "localhost";
    $username = "root";
    $password = "";
    $dbname = "shopping";
    $port = 3307;

    $conn = new mysqli($servername, $username, $password, $dbname, $port);

    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }

    // SQL query to create a view that combines data from users and orders
    $sql = "CREATE VIEW user_orders_view AS 
            SELECT u.name, u.email, o.product, o.amount
            FROM users u
            INNER JOIN orders o ON u.id = o.user_id";

    if ($conn->query($sql) === TRUE) {
        echo '<div class="message">View creation successful!</div>';
    } else {
        echo "Error creating view: " . $conn->error;
    }

    $conn->close();
    ?> <a href="http://localhost/exp/05_queries.html" class="go-home">Home</a>
</body>

</html>