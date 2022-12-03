package bsuir.wt.lr_4.servlet;

import bsuir.wt.lr_4.DAO.room.RoomDAOImpl;
import bsuir.wt.lr_4.service.room.RoomService;
import bsuir.wt.lr_4.service.room.RoomServiceImpl;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;

@WebServlet(name = "RoomCatalogServlet", value = "/roomCatalog")
public class RoomCatalogServlet extends HttpServlet {

    private RoomService roomService;
    private static final String INDEX = "/WEB-INF/view/roomCatalog.jsp";

    //TODO add RoomDAO
    @Override
    public void init() throws ServletException {
        roomService = new RoomServiceImpl(new RoomDAOImpl());
    }

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        RequestDispatcher dispatcher = request.getRequestDispatcher(INDEX);
        request.setAttribute("availableRooms", roomService.getAllRooms());
        dispatcher.forward(request, response);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }
}
