package bsuir.wt.lr_4.util;

import org.postgresql.ds.PGPoolingDataSource;

public class DataSourceConnection {

    private final static String DB_URL = System.getenv("DB_URL");
    private final static String DB_USERNAME = System.getenv("DB_USERNAME");
    private final static String DB_PASSWORD = System.getenv("DB_PASSWORD");
    private final static int DB_MAX_CONNECTIONS = 10;

    private static PGPoolingDataSource connectionPool = establishConnection();

    public static PGPoolingDataSource getConnectionPool() {
        return connectionPool;
    }

    public static PGPoolingDataSource establishConnection(){
        connectionPool = new PGPoolingDataSource();
        connectionPool.setURL(DB_URL);
        connectionPool.setUser(DB_USERNAME);
        connectionPool.setPassword(DB_PASSWORD);
        connectionPool.setMaxConnections(DB_MAX_CONNECTIONS);
        return connectionPool;
    }

}
