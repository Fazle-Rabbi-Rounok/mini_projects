<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8" />
    <link rel="stylesheet" href="cs.css" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Create Database</title>
    <style>
        body {
            margin: 0;
            padding: 0;
            font-family: "Arial", sans-serif;
            background: linear-gradient(120deg, #075e54, #128c7e);
            color: white;
            display: flex;
            justify-content: center;
            align-items: center;
            min-height: 100vh;
            position: relative;
            /* Required for absolute positioning of the button */
        }

        .container {
            max-width: 800px;
            width: 90%;
            padding: 30px;
            background: rgba(255, 255, 255, 0.1);
            border-radius: 15px;
            box-shadow: 0 10px 30px rgba(0, 0, 0, 0.2);
            text-align: center;
            border: 1px solid rgba(255, 255, 255, 0.2);
            animation: fadeIn 1s ease-in-out;
        }


        h1 {
            font-size: 36px;
            margin-bottom: 30px;
            color: white;
            font-family: "Georgia", serif;
            font-weight: 700;
            letter-spacing: 1px;
            text-shadow: 1px 1px 5px rgba(0, 0, 0, 0.3);
        }
    </style>
</head>

<body>
    <div class="container">
        <?php
        $servername = "localhost";
        $username = "root";
        $password = "";
        $dbname = "shopping";
        $port = 3307;

        // Create connection
        $conn = new mysqli($servername, $username, $password, $dbname, $port);

        // Check connection
        if ($conn->connect_error) {
            echo '<div class="message error">Connection failed: ' . $conn->connect_error . '</div>';
        }
        // SQL query to create a table
        $sql = "CREATE TABLE orders (
    id int auto_increment primary key,
    user_id INT not null,
    product VARCHAR(100) NOT NULL,
    amount double NOT NULL
    
)";

        // Execute the query
        if ($conn->query($sql) === TRUE) {
            echo '<div class="message">Table created successfully!</div>';

        } else {
            echo "Error creating table: " . $conn->error;
        }

        // Close the connection
        $conn->close();
        ?>
        <a href="http://localhost/exp/04_initialtask.html" class="go-home-button">Home</a>
    </div>
</body>

</html>