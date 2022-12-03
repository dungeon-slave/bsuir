<%@ page import="java.util.List" %>
<%@ page import="bsuir.wt.lr_4.model.Room" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <meta charset="UTF-8">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3" crossorigin="anonymous">
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-ka7Sk0Gln4gmtz2MlQnikT1wXgYsOg+OMhuP+IlRH9sENBO0LRn5q+8nbTov4+1p" crossorigin="anonymous"></script>
    <title>Catalog</title>
</head>
<body>
<table class="table table-striped table-bordered"  style="background-color: white">
    <thead>
    <tr>
        <th scope="col">Floor</th>
        <th scope="col">Price</th>
        <th scope="col">Type</th>
    </tr>
    </thead>
    <tbody>
        <%
            List<Room> rooms = (List<Room>) request.getAttribute("availableRooms");
            for (Room room: rooms) {
                String roomId = String.valueOf(room.getRoom_id());

        %>
        <tr>
            <td> <%=room.getFloor()%> </td>
            <td> <%=String.valueOf(room.getPrice())%> </td>
            <td> <%=String.valueOf(room.getRoomType())%> </td>
            <td>
                <form action="/booking?roomId=<%=roomId%>" method="post">
                    <button type="submit" class="btn btn-primary me-2 btn-sm btn-block">Book room</button>
                </form>
            </td>
        </tr>
        <%
            }
        %>
    </tbody>
</table>
</body>
</html>
