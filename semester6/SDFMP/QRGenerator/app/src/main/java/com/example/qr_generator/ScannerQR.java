package com.example.qr_generator;

import androidx.activity.result.ActivityResultLauncher;
import com.journeyapps.barcodescanner.ScanOptions;

public class ScannerQR
{
    public void scan(ActivityResultLauncher<ScanOptions> barLauncher)
    {
        ScanOptions options = new ScanOptions();
        options.setOrientationLocked(true);
        options.setCaptureActivity(CaptureAct.class);
        options.setDesiredBarcodeFormats(ScanOptions.QR_CODE);
        barLauncher.launch(options);
    }
}
