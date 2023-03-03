package com.example.rss;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.NodeList;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.ArrayList;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;

public class DownloadTask implements Runnable
{
    private final URL url;
    private final ArrayList<RssItem> items = new ArrayList<>();
    public DownloadTask(URL url)
    {
        this.url = url;
    }
    public ArrayList<RssItem> getItems() { return items; }
    @Override
    public void run()
    {
        try
        {
            HttpURLConnection connection = (HttpURLConnection) url.openConnection();
            connection.connect();
            if (connection.getResponseCode() == HttpURLConnection.HTTP_OK)
            {
                DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
                DocumentBuilder db = dbf.newDocumentBuilder();

                Document document = db.parse(connection.getInputStream());
                Element element = document.getDocumentElement();

                NodeList nodeList = element.getElementsByTagName("item");
                for (int i = 0, len = nodeList.getLength(); i < len; i++)
                {
                    Element entry = (Element) nodeList.item(i);
                    items.add(
                        new RssItem
                      (
                        entry.getElementsByTagName("title").item(0).getFirstChild().getNodeValue(),
                        entry.getElementsByTagName("link").item(0).getFirstChild().getNodeValue()
                      )
                            );
                }
            }
        }
        catch (Exception e)
        {
            throw new RuntimeException(e);
        }
    }
}
