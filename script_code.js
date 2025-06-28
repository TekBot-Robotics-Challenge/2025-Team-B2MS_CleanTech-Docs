function copierCode(id, bouton) {
const code = document.getElementById(id).innerText;
navigator.clipboard.writeText(code).then(() => {
const ancienTexte = bouton.innerText;
bouton.innerText = "✅";
bouton.disabled = true;

setTimeout(() => {
  bouton.innerText = ancienTexte;
  bouton.disabled = false;
}, 1500);
});
}

function telechargerCode(id, nomFichier, typeMime, bouton) {
  const code = document.getElementById(id).innerText;
  const blob = new Blob([code], { type: typeMime });
  const lien = document.createElement('a');
  lien.href = URL.createObjectURL(blob);
  lien.download = nomFichier;
  lien.click();

  const ancienTexte = bouton.innerText;
  bouton.innerText = "✅";
  bouton.disabled = true;

  setTimeout(() => {
    bouton.innerText = ancienTexte;
    bouton.disabled = false;
  }, 1500);
}