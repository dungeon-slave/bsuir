package bsuir.wt.lr_4.servlet;

import bsuir.wt.lr_4.DAO.booking.BookingDAOImpl;
import bsuir.wt.lr_4.service.booking.BookingService;
import bsuir.wt.lr_4.service.booking.BookingServiceImpl;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;

@WebServlet(name = "BookingServlet", value = "/booking")
public class BookingServlet extends HttpServlet {

    private BookingService bookingService;

    @Override
    public void init() throws ServletException {
        bookingService = new BookingServiceImpl(new BookingDAOImpl());
    }

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        resp.sendRedirect("/roomCatalog");
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        HttpSession session = req.getSession(false);

        final long customerId = (Long) session.getAttribute("user_id");
        final long roomId = Long.parseLong(req.getParameter("roomId"));

        bookingService.saveNewBooking(customerId, roomId);
        resp.sendRedirect("/roomCatalog");
    }
}
