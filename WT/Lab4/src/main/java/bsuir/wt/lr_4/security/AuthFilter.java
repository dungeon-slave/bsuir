package bsuir.wt.lr_4.security;

import javax.servlet.*;
import javax.servlet.annotation.*;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;

@WebFilter(filterName = "AuthFilter", urlPatterns = "/*")
public class AuthFilter implements Filter {

    private final String LOGIN_URI = "/login";
    private final String REGISTRATION_URI = "/registration";

    public void init(FilterConfig config) throws ServletException {
    }

    public void destroy() {
    }

    @Override
    public void doFilter(ServletRequest request, ServletResponse response, FilterChain chain) throws ServletException, IOException {
        HttpServletRequest req = (HttpServletRequest) request;
        HttpServletResponse resp = (HttpServletResponse) response;

        HttpSession session  = req.getSession(false);
        final String loginUri = req.getContextPath() +  LOGIN_URI;
        final String registrationUri = req.getContextPath() +  REGISTRATION_URI;

        boolean isLoggedIn = session != null && session.getAttribute("email") != null;
        boolean isLoginRequest = req.getRequestURI().equals(loginUri);
        boolean isRegistrationRequest = req.getRequestURI().equals(registrationUri);

        if (isLoggedIn || isLoginRequest || isRegistrationRequest) {
            chain.doFilter(request, response);
        }
        else {
            resp.sendRedirect(LOGIN_URI);
        }
    }
}
