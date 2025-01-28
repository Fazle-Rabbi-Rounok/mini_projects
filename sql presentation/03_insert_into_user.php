<!DOCTYPE html>
<html lang="en">

<head>
    <link rel="stylesheet" href="cs.css" />
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Insert Data</title>
    <style>
        table {
            width: 100%;
            border-collapse: collapse;
        }

        th,
        td {
            border: 1px solid #ddd;
            padding: 8px;
            text-align: left;
        }

        th {
            background-color: #f2f2f2;
        }
    </style>
</head>

<body>

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

    $sql = "INSERT INTO users (name, email, age)
VALUES
('Arafat Rahman', 'arafat.rahman@example.com', 21),
('Emili Khan', 'emili.khan@example.com', 22),
('Mizanur Rahman', 'mizanur.rahman@example.com', 23),
('Sadia Akter', 'sadia.akter@example.com', 22),
('Jamal Ahmed', 'jamal.ahmed@example.com', 22),
('Tasnim Chowdhury', 'tasnim.chowdhury@example.com', 28),
('Rafiqul Islam', 'rafiqul.islam@example.com', 27),
('Nusrat Jahan', 'nusrat.jahan@example.com', 28)
";

    if ($conn->query($sql) === TRUE) {
        echo '<div class="message">Data inserted successfully.</div>';
    } else {
        echo "Error: " . $sql . "<br>" . $conn->error;
    }

    $conn->close();
    ?>
    <a href="http://localhost/exp/04_initialtask.html" class="go-home-button">Home</a>
</body>

</html>