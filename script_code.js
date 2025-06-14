function copierCode(id) {
  const code = document.getElementById(id).innerText;
  navigator.clipboard.writeText(code).then(() => {
    alert("Code copié !");
  });
}

function telechargerCode(id, nomFichier, typeMime) {
  const code = document.getElementById(id).innerText;
  const blob = new Blob([code], { type: typeMime });
  const lien = document.createElement('a');
  lien.href = URL.createObjectURL(blob);
  lien.download = nomFichier;
  lien.click();
}
