<!DOCTYPE html>
<html lang="en">

<head>
    <link rel="stylesheet" href="cs.css" />
    <meta charset="UTF-8" />
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
        $port = 3307;

        $conn = new mysqli($servername, $username, $password, '', $port);

        if ($conn->connect_error) {
            echo '<div class="message error">Connection failed: ' . $conn->connect_error . '</div>';
        } else {
            // Create database
            $sql = "CREATE DATABASE if not exists shopping";
            if ($conn->query($sql) === TRUE) {
                echo '<div class="message">Database successfully created.</div>';
            } else {
                echo '<div class="message error">Error creating database: ' . $conn->error . '</div>';
            }

            $conn->close();
        }
        ?>
        <a href="http://localhost/exp/04_initialtask.html" class="go-home-button">Home</a>
    </div>
</body>

</html>