package bsuir.wt.lr_4.DAO.room;

import bsuir.wt.lr_4.model.Room;
import bsuir.wt.lr_4.model.RoomType;
import bsuir.wt.lr_4.util.DataSourceConnection;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class RoomDAOImpl implements RoomDAO {

    @Override
    public List<Room> getAll() {
        try (Connection connection = DataSourceConnection.getConnectionPool().getConnection()) {
                PreparedStatement findAllHotelrooms = connection.prepareStatement(
                    "SELECT room_id, floor, price, room_type.type_name FROM room JOIN room_type ON room.room_id = room_type.room_type_id;"
            );
            ResultSet resultSet = findAllHotelrooms.executeQuery();
            List<Room> rooms = new ArrayList<>();
            while (resultSet.next()) {
                Room room = Room.builder()
                        .room_id(resultSet.getLong("room_id"))
                        .floor(resultSet.getInt("floor"))
                        .price(resultSet.getFloat("price"))
                        .roomType(RoomType.valueOf(resultSet.getString("type_name")))
                        .build();
                rooms.add(room);
            }
            return rooms;
        } catch (SQLException e) {
            e.printStackTrace();
            return null;
        }
    }
}
