package bsuir.wt.lr_4.DAO.booking;

;import bsuir.wt.lr_4.util.DataSourceConnection;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class BookingDAOImpl implements BookingDAO {

    @Override
    public void bookRoom(long customerId, long roomId) {
        try (Connection connection = DataSourceConnection.getConnectionPool().getConnection()) {
            PreparedStatement saveNewBookingQuery = connection.prepareStatement(
                    "INSERT INTO booking (customer_id, booked_room_id)" +
                            "VALUES (?, ?)"
            );
            saveNewBookingQuery.setLong(1, customerId);
            saveNewBookingQuery.setLong(2, roomId);
            saveNewBookingQuery.execute();
        } catch (SQLException e) {
            e.printStackTrace();
        }

    }
}
