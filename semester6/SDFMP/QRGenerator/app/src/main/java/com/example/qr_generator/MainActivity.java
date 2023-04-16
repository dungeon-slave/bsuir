package com.example.qr_generator;

import androidx.activity.result.ActivityResultLauncher;
import androidx.appcompat.app.AppCompatActivity;
import android.content.ClipData;
import android.content.ClipboardManager;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.Toast;
import com.journeyapps.barcodescanner.ScanContract;
import com.journeyapps.barcodescanner.ScanOptions;

public class MainActivity extends AppCompatActivity
{
    private final GeneratorQR generator = new GeneratorQR();
    private final ScannerQR scanner = new ScannerQR();
    private ImageView qrImage;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Button btnGenerate = findViewById(R.id.btnGenerate);
        Button btnScan = findViewById(R.id.btnScan);
        qrImage = findViewById(R.id.imageViewQR);

        btnGenerate.setOnClickListener(callback ->
        {
            try
            {
                EditText editText = findViewById(R.id.editTextToGenerate);
                qrImage.setImageBitmap(generator.generate(editText.getText().toString()));
            }
            catch(Exception e)
            {
                Toast.makeText(this, "QR GENERATOR EXCEPTION!", Toast.LENGTH_LONG).show();
            }
        });

        btnScan.setOnClickListener(callback ->
        {
            try
            {
                scanner.scan(barLauncher);
            }
            catch (Exception e)
            {
                Toast.makeText(this, "QR SCANNER EXCEPTION!", Toast.LENGTH_LONG).show();
            }
        });
    }
    ActivityResultLauncher<ScanOptions> barLauncher = registerForActivityResult(new ScanContract(),
            result -> {
                ClipData clipData;
                ClipboardManager clipboardManager = (ClipboardManager)getSystemService(CLIPBOARD_SERVICE);
                if (result.getContents() != null)
                {
                    if(result.getContents().startsWith("http://") || result.getContents().startsWith("https://"))
                    {
                        startActivity(new Intent(Intent.ACTION_VIEW, Uri.parse(result.getContents())));
                    }
                    else
                    {
                        clipData = ClipData.newPlainText("text",result.getContents());
                        clipboardManager.setPrimaryClip(clipData);
                        Toast.makeText(getApplicationContext(),"Text Copied ",Toast.LENGTH_SHORT).show();
                    }
                }
            });
}