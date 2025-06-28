// Menu burger responsive
document.getElementById("sidebarToggle").addEventListener("click", () => {
document.querySelector(".sidebar").classList.toggle("open");
});

// Gérer activation des domaines
document.querySelectorAll(".tab-button").forEach(button => {
button.addEventListener("click", e => {
document.querySelectorAll(".tab-button").forEach(btn => btn.classList.remove("active"));
e.currentTarget.classList.add("active");

// Afficher le contenu lié
document.querySelectorAll(".tab-content").forEach(tc => tc.classList.remove("active"));
const target = e.currentTarget.getAttribute("data-target");
if (target) document.getElementById(target).classList.add("active");
});
});

// Sous-onglets
document.querySelectorAll(".subtab-button").forEach(button => {
button.addEventListener("click", e => {
const parent = e.currentTarget.closest(".tab-content");
parent.querySelectorAll(".subtab-button").forEach(btn => btn.classList.remove("active"));
e.currentTarget.classList.add("active");

parent.querySelectorAll(".subtab-content").forEach(content => content.classList.remove("active"));
const target = e.currentTarget.getAttribute("data-target");
parent.querySelector("#" + target).classList.add("active");
});
});

// script_commun.js
document.getElementById("sidebarToggle").addEventListener("click", () => {
  document.querySelector(".sidebar").classList.toggle("open");
});


// Gestion activation des projets (subtab-button)
document.querySelectorAll(".subtab-button").forEach(button => {
  button.addEventListener("click", e => {
    // Enlever active sur tous les boutons
    document.querySelectorAll(".subtab-button").forEach(btn => btn.classList.remove("active"));
    e.currentTarget.classList.add("active");

    // Afficher le contenu lié
    const parent = e.currentTarget.closest(".nav-section");
    parent.querySelectorAll(".subtab-content").forEach(tc => tc.classList.remove("active"));
    const target = e.currentTarget.getAttribute("data-target");
    if (target) document.getElementById(target).classList.add("active");

    // Afficher la sous-navigation liée au projet actif uniquement
    parent.querySelectorAll(".project-subnav").forEach(nav => nav.classList.remove("active"));
    const subnavId = "subnav-" + target;
    const activeSubnav = document.getElementById(subnavId);
    if (activeSubnav) activeSubnav.classList.add("active");
  });
});
