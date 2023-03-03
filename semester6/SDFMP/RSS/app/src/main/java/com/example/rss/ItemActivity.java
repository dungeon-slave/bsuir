package com.example.rss;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.webkit.WebResourceRequest;
import android.webkit.WebView;
import android.webkit.WebViewClient;

public class ItemActivity extends AppCompatActivity
{
    private String URL;
    private WebView webView;
    private WebViewClient webClient;
    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_item);
        URL = getIntent().getStringExtra("URL");
        webView = findViewById(R.id.webView);
        webClient = new WebViewClient()
        {
            @Override
            public boolean shouldOverrideUrlLoading(WebView view, WebResourceRequest request)
            {
                view.loadUrl(request.getUrl().toString());
                return true;
            }
        };
    }
    @Override
    protected void onStart()
    {
        super.onStart();
        try
        {
            webView.loadUrl(URL);
            webView.setWebViewClient(webClient);
        }
        catch(Exception e)
        {
            throw new RuntimeException(e);
        }
    }
}