package bsuir.wt.lr_4.servlet;

import bsuir.wt.lr_4.DAO.user.UserDAOImpl;
import bsuir.wt.lr_4.model.User;
import bsuir.wt.lr_4.service.user.UserService;
import bsuir.wt.lr_4.service.user.UserServiceImpl;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;

@WebServlet(name = "LoginServlet", value = "/login")
public class LoginServlet extends HttpServlet {

    private static final String INDEX = "/WEB-INF/view/loginPage.jsp";
    private static final String ROOM_CATALOG_INDEX = "/WEB-INF/view/roomCatalog.jsp";



    private UserService userService;

    @Override
    public void init(ServletConfig config) throws ServletException {
        userService = new UserServiceImpl(new UserDAOImpl());
    }

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        req.getRequestDispatcher(INDEX).forward(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        req.setCharacterEncoding("UTF-8");

        final String email = req.getParameter("email");
        final String password = req.getParameter("password");

        User user = userService.findUserByAuthData(email, password);

        if (user != null) {
            HttpSession session = req.getSession(false);
            session.setAttribute("user_id", user.getId());
            session.setAttribute("email", user.getEmail());
            session.setAttribute("role", user.getRole().toString());
            resp.sendRedirect(req.getContextPath() + "/roomCatalog");
        } else {
            System.out.println("null");
        }

    }
}
