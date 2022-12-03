package bsuir.wt.lr_4.service.booking;

import bsuir.wt.lr_4.DAO.booking.BookingDAO;

public class BookingServiceImpl implements BookingService {

    private final BookingDAO bookingDAO;

    public BookingServiceImpl(BookingDAO bookingDAO) {
        this.bookingDAO = bookingDAO;
    }

    @Override
    public void saveNewBooking(long customerId, long roomId) {
        bookingDAO.bookRoom(customerId, roomId);
    }
}