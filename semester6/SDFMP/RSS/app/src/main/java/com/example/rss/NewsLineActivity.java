package com.example.rss;

import androidx.appcompat.app.AppCompatActivity;
import android.content.Context;
import android.content.Intent;
import android.net.ConnectivityManager;
import android.net.NetworkCapabilities;
import android.os.Bundle;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.Toast;
import java.net.URL;
import java.util.ArrayList;

public class NewsLineActivity extends AppCompatActivity
{
    private ArrayList<RssItem> rssItems = new ArrayList<>();
    private String rssPath;
    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_newsline);

        Button btnLoad = findViewById(R.id.button);
        btnLoad.setOnClickListener(v -> {
            try
            {
                if (isNetworkAvailable())
                {
                    EditText urlEdit = findViewById(R.id.editTextURL);
                    rssPath = urlEdit.getText().toString();
                    updateItemsList();
                    drawItems();
                }
                else
                {
                    Toast.makeText(this, "NETWORK ERROR!", Toast.LENGTH_LONG).show();
                }
            }
            catch(Exception e)
            {
                throw new RuntimeException(e);
            }
        });
    }
    private void updateItemsList()
    {
        try
        {
            DownloadTask task = new DownloadTask(new URL(rssPath));
            Thread downloadThread = new Thread(task);
            downloadThread.start();
            downloadThread.join();
            rssItems = task.getItems();
        }
        catch (Exception e)
        {
            Toast.makeText(NewsLineActivity.this, "LIST UPDATING ERROR!", Toast.LENGTH_LONG).show();
        }
    }
    private void drawItems()
    {
        ListView rssListView = findViewById(R.id.rssListView);
        ArrayList<String> titles = new ArrayList<>();

        for (RssItem item: rssItems)
        {
            titles.add(item.getTitle());
        }
        ArrayAdapter<String> adapter = new ArrayAdapter<>(this, androidx.appcompat.R.layout.support_simple_spinner_dropdown_item, titles);
        rssListView.setAdapter(adapter);
        rssListView.setOnItemClickListener((parent, view, position, id) -> {
            Intent intent = new Intent(NewsLineActivity.this, ItemActivity.class);
            intent.putExtra("URL", rssItems.get(position).getLink());
            startActivity(intent);
        });
    }
    private boolean isNetworkAvailable()
    {
        ConnectivityManager connectivityManager = (ConnectivityManager) getSystemService(Context.CONNECTIVITY_SERVICE);
        NetworkCapabilities capabilities = connectivityManager.getNetworkCapabilities(connectivityManager.getActiveNetwork());

        return capabilities != null && capabilities.hasCapability(NetworkCapabilities.NET_CAPABILITY_VALIDATED);
    }
}