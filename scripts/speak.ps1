Add-Type -AssemblyName System.Speech

if (-not $global:BrindiSpeaker) {
    try {
        $global:BrindiSpeaker = New-Object System.Speech.Synthesis.SpeechSynthesizer
        $global:BrindiSpeaker.SetOutputToDefaultAudioDevice()
    } catch {
        Write-Host " Aucun périphérique audio actif."
        exit 1
    }
}

try {
    $global:BrindiSpeaker.Speak($args[0])
} catch {
    Write-Host " Erreur audio : $($_.Exception.Message)"
}
